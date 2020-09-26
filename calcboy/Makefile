apps += Calcboy::App
app_headers += apps/calcboy/app.h

include apps/calcboy/emu/Makefile

ifeq ($(PLATFORM),device)
SFLAGS += -DDEVICE
endif

apps_src += $(addprefix apps/calcboy/,\
  app.cpp \
  calcboy_controller.cpp \
  calcboy_view.cpp \
)


app_images += apps/calcboy/calcboy_icon.png

i18n_files += $(addprefix apps/calcboy/,\
  base.universal.i18n \
)

$(eval $(call depends_on_image,apps/calcboy/app.cpp,apps/calcboy/calcboy_icon.png))
