bees = ../../apps/bees
sim = ../avr32_sim

# bees sources
src += 	$(bees)/src/app_timers.c \
	$(bees)/src/net.c \
	$(bees)/src/net_midi.c \
	$(bees)/src/net_monome.c \
	$(bees)/src/net_poll.c \
	$(bees)/src/op.c \
	$(bees)/src/op_math.c \
	$(bees)/src/param.c \
	$(bees)/src/pages.c \
	$(bees)/src/pickle.c \
	$(bees)/src/play.c \
	$(bees)/src/preset.c \
	$(bees)/src/render.c \
	$(bees)/src/param_scaler.c \
	$(bees)/src/scene.c \
	$(bees)/src/util.c \
	$(bees)/src/ops/op_add.c \
	$(bees)/src/ops/op_accum.c \
	$(bees)/src/ops/op_adc.c \
	$(bees)/src/ops/op_div.c \
	$(bees)/src/ops/op_enc.c \
	$(bees)/src/ops/op_gate.c \
	$(bees)/src/ops/op_list8.c \
	$(bees)/src/ops/op_metro.c \
	$(bees)/src/ops/op_midi_note.c \
	$(bees)/src/ops/op_mul.c \
	$(bees)/src/ops/op_monome_grid_raw.c \
	$(bees)/src/ops/op_preset.c \
	$(bees)/src/ops/op_split.c \
	$(bees)/src/ops/op_sub.c \
	$(bees)/src/ops/op_sw.c \
	$(bees)/src/ops/op_timer.c \
	$(bees)/src/ops/op_thresh.c \
	$(bees)/src/ops/op_tog.c \
	$(bees)/src/ops/op_random.c \
	$(bees)/src/pages/page_dsp.c \
	$(bees)/src/pages/page_gathered.c \
	$(bees)/src/pages/page_ins.c \
	$(bees)/src/pages/page_ops.c \
	$(bees)/src/pages/page_outs.c \
	$(bees)/src/pages/page_play.c \
	$(bees)/src/pages/page_presets.c \
	$(bees)/src/pages/page_scenes.c \
	$(bees)/src/scalers/scaler_amp.c \
	$(bees)/src/scalers/scaler_bool.c \
	$(bees)/src/scalers/scaler_fix.c \
	$(bees)/src/scalers/scaler_integrator.c \
	$(bees)/src/scalers/scaler_note.c \
	$(bees)/src/scalers/scaler_svf_fc.c


# "fake" sources
src += 	src/app_bees.c
src += 	src/flash_bees.c
src += 	src/files.c
src +=	src/handler.c

#includes
inc = 	$(bees) \
	$(bees)/src \
	$(bees)/../../common \
	$(sim) \
	$(sim)/src \
	$(sim)/src/usb \
	$(sim)/src/usb/midi \
	$(sim)/src/usb/ftdi \
	$(sim)/src/usb/hid \
	$(sim)/src/usb/mouse \
	$(sim)/src/usb/hub \

include $(sim)/avr32_sim.mk

ifdef BUILD_DIR
	build-dir       := $(dir $(BUILD_DIR))$(if $(notdir $(BUILD_DIR)),$(notdir $(BUILD_DIR))/)
else
	build-dir        =
endif

obj = $(addprefix $(build-dir), $(addsuffix .o,$(basename $(src))))

cflags += $(foreach path,$(inc),-I$(path))

$(build-dir)%.o: %.c 
	echo $(cflags)
	$(Q)test -d $(dir $@) || mkdir -p $(dir $@)
	gcc $(cflags) -g -c $< -o $@

beekeep: $(obj)	
	echo $(obj)
	gcc $(obj) -g $(cflags) -o beekeep

all: beekeep

clean:
	rm $(obj)