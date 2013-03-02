
#include "bfin_core.h"
#include "isr.h"
#include "init.h"

//------ global variables initialized here

/* // AD1836 config registers */
/* static volatile short codec1836TxRegs[CODEC_1836_REGS_LENGTH] = { */
/*   DAC_CONTROL_1	| 0x000, */
/*   DAC_CONTROL_2	| 0x000, */
/*   DAC_VOLUME_0	| 0x3ff, */
/* /\*   DAC_VOLUME_1	| 0x3ff, *\/ */
/* /\*   DAC_VOLUME_2	| 0x3ff, *\/ */
/* /\*   DAC_VOLUME_3	| 0x3ff, *\/ */
/* /\*   DAC_VOLUME_4	| 0x000, *\/ */
/* /\*   DAC_VOLUME_5	| 0x000, *\/ */
/* /\*   ADC_CONTROL_1	| 0x000, *\/ */
/* /\*   ADC_CONTROL_2	| 0x000, *\/ */
/* /\*   ADC_CONTROL_3	| 0x000 *\/ */
/* /\* }; *\/ */


// control registers and associated values for AD1939
static volatile short codec1939TxRegs[CODEC_1939_NUM_REGS][2] = {
  {  PLL_CLOCK_0        , 0x80 } , // enable, xtal->master->PLL
  {  PLL_CLOCK_1        , 0x00 } ,
  {  DAC_CONTROL_0      , 0x00 } ,
  {  DAC_CONTROL_1      , 0x00 } ,
  {  DAC_CONTROL_2      , 0x00 } ,
  {  DAC_MUTE           , 0x00 } ,
  {  DAC_L1_VOLUME      , 0x00 } ,
  {  DAC_R1_VOLUME      , 0x00 } ,
  {  DAC_L2_VOLUME      , 0x00 } ,
  {  DAC_R2_VOLUME      , 0x00 } ,
  {  DAC_L3_VOLUME      , 0x00 } ,
  {  DAC_R3_VOLUME      , 0x00 } ,
  {  DAC_L4_VOLUME      , 0x00 } ,
  {  DAC_R4_VOLUME      , 0x00 } ,
  {  ADC_CONTROL_0      , 0x00 } ,
  {  ADC_CONTROL_1      , 0x00 } ,
  {  ADC_CONTROL_2      , 0x00 }
};

// SPORT0 DMA transmit buffer
volatile s32 iTxBuf[4];
// SPORT0 DMA receive buffer
volatile s32 iRxBuf[4];

//----- function definitions
// initialize clocks
void init_clocks(void) {
  //// check:
  //  const u16 pll_ctl = *pPLL_CTL;
  //  const u16 pll_div = *pPLL_DIV;
  //  u8 dum = 0;
  //  dum++;
  //  dum++;

  // set MSEL = 20 for core clock of 108Mhz
//  *pPLL_CTL = 0x2800;
/////// changing to 533Mhz part
/// MSEL = 19
  //// VCO = 19 * CLKIN = 513
  *pPLL_CTL = 0x2600;
  ssync();
  
}

// initialize EBI
void init_EBIU(void) {
  //  straight from the self-test example project
  // Initalize EBIU control registers to enable all banks
  *pEBIU_AMBCTL1 = 0xFFFFFF02;
  ssync();
  
  // -- not sure why there is a read here, possibly anomaly 05000157?
  //temp = *pEBIU_AMBCTL1;
  //temp++;
  
  *pEBIU_AMGCTL = 0x00FF;
  ssync();
  
  // Check if already enabled
  if( SDRS != ((*pEBIU_SDSTAT) & SDRS) ) {
    return;
  }
  
  //SDRAM Refresh Rate Control Register
  //  *pEBIU_SDRRC = 0x01A0;
  // for 108Mhz system clock:
  *pEBIU_SDRRC = 835;
  
  //SDRAM Memory Bank Control Register
  *pEBIU_SDBCTL = 0x0025; //1.7	64 MB
  //	*pEBIU_SDBCTL = 0x0013;	//1.6 and below 32 MB
  
  //SDRAM Memory Global Control Register
  *pEBIU_SDGCTL = 0x0091998d;//0x998D0491;
  ssync();
}

void init_flash(void) {
  // flash A, port A0 -> AD1836_reset
  //  *pFlashA_PortA_Dir = 0x1;
  // flash A, ports [B0, B5] -> [led1, led6]
  //  *pFlashA_PortB_Dir = 0x3f;
}

/* // setup SPI0 -> AD1836 config */
/* void init_1836(void) { */
/*   int i; */
/*   int j; */
/*   // write to Port A to reset AD1836 */
/*   *pFIO_FLAG_D &= CODEC_RESET_MASK; */
/*   // write to Port A to enable AD1836 */
/*   *pFIO_FLAG_D |= (0xffff ^ CODEC_RESET_MASK); */
/*   // wait to recover from reset */
/*   for (i=0; i<0xf0000; i++) asm("nop;"); */
/*   // Enable PF4 peripheral function */
/*   *pSPI_FLG = FLS4; */
/*   // Set baud rate SCK = HCLK/(2*SPIBAUD) SCK = 2MHz	 */
/*   *pSPI_BAUD = 16; */
/*   // configure spi port */
/*   // SPI DMA write, 16-bit data, MSB first, SPI Master */
/*   *pSPI_CTL = TIMOD_DMA_TX | SIZE | MSTR; */
/*   // Set up DMA5 to transmit */
/*   // Map DMA5 to SPI */
/*   *pDMA5_PERIPHERAL_MAP	= 0x5000; */
/*   // Configure DMA5 */
/*   // 16-bit transfers */
/*   *pDMA5_CONFIG = WDSIZE_16; */
/*   // point DMA at the configuration data */
/*   *pDMA5_START_ADDR = (void *)codec1836TxRegs; */
/*   // DMA inner loop count */
/*   *pDMA5_X_COUNT = CODEC_1836_REGS_LENGTH; */
/*   // Inner loop address increment */
/*   *pDMA5_X_MODIFY = 2; */
/*   // enable DMAs */
/*   *pDMA5_CONFIG = (*pDMA5_CONFIG | DMAEN); */
/*   // enable spi */
/*   *pSPI_CTL = (*pSPI_CTL | SPE); */
/*   // wait until DMA transfers for spi are finished  */
/*   for (j=0; j<0xaff0; j++) asm("nop;"); */
/*   // disable spi */
/*   *pSPI_CTL = 0x0000; */
/*   // disable dma5 */
/*   *pDMA5_CONFIG = (*pDMA5_CONFIG & ~DMAEN); */
/* } */

static void spi_send_byte(u8 ch) {
  //  unsigned short dummyread;

  ////////
  //// dbg
  unsigned long int stat;
  unsigned long int txs = TXS;
  unsigned long int spif = SPIF;
  unsigned long int rxs = RXS;
  unsigned long int tdbr;
  unsigned long int rdbr;
  unsigned long int ctl;
  /////////

  *pSPI_TDBR = ch;
  ssync();

  /////// dbg
  stat = *pSPI_STAT;
  tdbr = *pSPI_TDBR;
  rdbr = *pSPI_RDBR;
  ctl = *pSPI_CTL;
  ///////

  while( (*pSPI_STAT & TXS)  != 0 ) {
    /////// dbg
    stat = *pSPI_STAT;
    tdbr = *pSPI_TDBR;
    rdbr = *pSPI_RDBR;
    ctl = *pSPI_CTL;
    ///////
  }
  while( (*pSPI_STAT & SPIF) == 0 ) { 
    /////// dbg
    stat = *pSPI_STAT;
    tdbr = *pSPI_TDBR;
    rdbr = *pSPI_RDBR;
    ctl = *pSPI_CTL;
    ///////
  }
  /* while( (*pSPI_STAT & RXS)  == 0 )  {  */
  /*   /////// dbg */
  /*   stat = *pSPI_STAT; */
  /*   tdbr = *pSPI_TDBR; */
  /*   rdbr = *pSPI_RDBR; */
  /*   ctl = *pSPI_CTL; */
  /*   /////// */
  /* } */
  /// dummy read to clear RX register
  //  dummyread = *pSPI_RDBR;

  /////// dbg
  stat = *pSPI_STAT;
  tdbr = *pSPI_TDBR;
  rdbr = *pSPI_RDBR;
  ctl = *pSPI_CTL;
  ///////

}

 // setup SPI0 -> AD1939 config */
void init_1939(void) { 
  u8 i; 
  u32 del;

  //// reset codec
  *pFIO_FLAG_D &= CODEC_RESET_MASK;
  // write to Port A to enable codec
  *pFIO_FLAG_D |= (0xffff ^ CODEC_RESET_MASK);
  
  //// TESTING:
  /// wait for the codec to reset
  /// from the datasheet, this could take an absolute maximum of (4096 / 6.9Mhz)s (?)
  /// we are using BF clock = 513 MHz, so:
  del = 308000; while(del--) { ;; } 

  //  set PF4 as slave select
  *pSPI_FLG = 0xFF10;

  // Set baud rate SCK = HCLK/(2*SPIBAUD) SCK = 2MHz
  *pSPI_BAUD = 16;

  // setup SPI:
  /// master, non-DMA mode, 8b transfers, MSB first,
  /// TX on buffer write, clock rising edge:

  //// this would give us the waveform we want but puts CS under hardware control
  //  *pSPI_CTL = MSTR | TIMOD_BUF_TX;

  /// SPI controller can't do 24-bits transfers--
  /// workaround: 8-bit transfers and manual slave select
  // ( see http://ez.analog.com/thread/1248
  //  SS from software :
  *pSPI_CTL = MSTR | CPHA | CPOL | TIMOD_BUF_TX;

  // enable SPI
  *pSPI_CTL = (*pSPI_CTL | SPE);

  ssync();
  // loop over registers
  for(i=0; i<CODEC_1939_NUM_REGS; i++) {
    // select slave
    //    *pFIO_FLAG_D &= CODEC_SS_MASK;

    // bring SS low (PF4)
    *pSPI_FLG = 0xef10;

    // send command byte
    spi_send_byte(CODEC_CMD_BYTE);
    // send register byte
    spi_send_byte(codec1939TxRegs[i][0]);
    /// send dta byte
    spi_send_byte(codec1939TxRegs[i][1]);
    
    // bring SS high (PF4)
    *pSPI_FLG = 0xff10;
  }
} // init_1939


//--------------------------------------------------------------------//
// init_spi_slave()
// (re-)configure spi in slave mode to receive control data from avr32 
void init_spi_slave(void) {
  int j;
  // don't attempt to drive the clock
  *pSPI_BAUD = 0;
  // reset the flags register? to defaults?
  *pSPI_FLG = 0xff00;

  // try clearing the rx error bit? (sticky - W1C)
  *pSPI_STAT |= 0x10;  
  *pSPI_STAT |= 0x10;  
  // slave mode, 16 bit transfers, MSB first, non-dma rx mode, overwrite (interrupt when SPI_RDBR is full) 
  // phase: seems crazy but i think bfin and avr32 have opposite definitions of clock phase! oh lordy
  //  *pSPI_CTL = CPHA | SIZE | GM;
  // actually need 8 bits to be compatible with SPI-boot
  //----->>>>>  *pSPI_CTL = CPHA | GM;
  *pSPI_CTL = CPHA | GM | SZ;
  // enable transmit on MISO
  *pSPI_CTL |= EMISO;
  // enable spi (now in slave mode)
  *pSPI_CTL = (*pSPI_CTL | SPE);
  // clear the spi rx register by reading from it
  j = *pSPI_RDBR;
  // clear the rx error bit (sticky - W1C)
  *pSPI_STAT |= 0x10;
}

// configure sport0 for i2s mode with external clock
void init_sport0(void)
{
  // Sport0 receive configuration
  // External CLK, External Frame sync, MSB first, Active Low
  // 24-bit data, Stereo frame sync enable
  *pSPORT0_RCR1 = RFSR | RCKFE;
  *pSPORT0_RCR2 = SLEN_24 | RXSE | RSFSE;
  
  // Sport0 transmit configuration
  // External CLK, External Frame sync, MSB first, Active Low
  // 24-bit data, Secondary side enable, Stereo frame sync enable
  *pSPORT0_TCR1 = TFSR | TCKFE;
  *pSPORT0_TCR2 = SLEN_24 | TXSE | TSFSE;
}

// initialize DMA in autobuffer mode
void init_DMA(void) {
  // Set up DMA1 to receive
  // Map DMA1 to Sport0 RX
  *pDMA1_PERIPHERAL_MAP = 0x1000;
  
  // Configure DMA1
  // 32-bit transfers, Interrupt on completion, Autobuffer mode
  *pDMA1_CONFIG = WNR | WDSIZE_32 | DI_EN | FLOW_1;
  // Start address of data buffer
  *pDMA1_START_ADDR = (void *)iRxBuf;
  // DMA inner loop count
  *pDMA1_X_COUNT = 4;
  // Inner loop address increment
  *pDMA1_X_MODIFY = 4;
  
  // Set up DMA2 to transmit
  // Map DMA2 to Sport0 TX
  *pDMA2_PERIPHERAL_MAP = 0x2000;
  
  // Configure DMA2
  // 32-bit transfers, Autobuffer mode
  *pDMA2_CONFIG = WDSIZE_32 | FLOW_1;
  // Start address of data buffer
  *pDMA2_START_ADDR = (void *)iTxBuf;
  // DMA inner loop count
  *pDMA2_X_COUNT = 4;
  // Inner loop address increment
  *pDMA2_X_MODIFY = 4;
}

// enable sport0 DMA
void enable_DMA_sport0(void) {
  // enable DMAs
  *pDMA2_CONFIG	= (*pDMA2_CONFIG | DMAEN);
  *pDMA1_CONFIG	= (*pDMA1_CONFIG | DMAEN);
  
  // enable Sport0 TX and RX
  *pSPORT0_TCR1 	= (*pSPORT0_TCR1 | TSPEN);
  *pSPORT0_RCR1 	= (*pSPORT0_RCR1 | RSPEN);
}

// initialize programmable flags for button input
void init_flags(void) {
  // inputs 
  *pFIO_INEN = PF_IN;
  // outputs
  *pFIO_DIR = PF_DIR;
  // edge-sensitive
  *pFIO_EDGE = 0x0f00;
  // both rise and fall
  *pFIO_BOTH = 0x0f00;
  // set interrupt mask
  *pFIO_MASKA_D = 0x0f00;
}

// assign interrupts
void init_interrupts(void) {
  int i=0;

  // assign core IDs to peripheral interrupts:
  *pSIC_IAR0 = 0xffffffff;
  // sport0 rx (dma1) -> ID2 = IVG9 
  // spi rx           -> ID3 = IVG10
  *pSIC_IAR1 = 0xff3fff2f;
  // PFA              -> ID5 = IVG12
  //  *pSIC_IAR2 = 0xffff5fff;
  // no buttons
   *pSIC_IAR2 = 0xffffffff;

  // assign ISRs to interrupt vectors:
  *pEVT9 = sport0_rx_isr;
  *pEVT10 = spi_rx_isr;
  //  *pEVT12 = pf_isr;

	// unmask in the core event processor
  //  asm volatile ("cli %0; bitset (%0, 9); bitset(%0, 10); bitset (%0, 12); sti %0; csync;": "+d"(i));
  asm volatile ("cli %0; bitset (%0, 9); bitset(%0, 10); sti %0; csync;": "+d"(i));
  
  // unmask in the peripheral interrupt controller
  //  *pSIC_IMASK = 0x00082200;
  *pSIC_IMASK = 0x00002200;
}
