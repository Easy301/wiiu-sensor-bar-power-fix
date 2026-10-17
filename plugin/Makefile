# Wii U Rear SensorBar — menu-only and always-on variants

ifeq ($(strip $(DEVKITPRO)),)
$(error "Please set DEVKITPRO. export DEVKITPRO=/opt/devkitpro")
endif

VARIANT ?= menu

ifeq ($(VARIANT),always)
  TARGET := rearsensorbar-always
  BUILD := build-always
  MODE_FLAGS := -DREAR_SENSORBAR_ALWAYS_ON=1
else
  TARGET := rearsensorbar-menu
  BUILD := build-menu
  MODE_FLAGS := -DREAR_SENSORBAR_ALWAYS_ON=0
endif

TOPDIR ?= $(CURDIR)
include $(DEVKITPRO)/wups/share/wups_rules

WUT_ROOT := $(DEVKITPRO)/wut
WUMS_ROOT := $(DEVKITPRO)/wums

SOURCES := src
DATA := data
INCLUDES := src

CFLAGS := -Wall -O2 -ffunction-sections $(MACHDEP)
CFLAGS += $(INCLUDE) -D__WIIU__ -D__WUT__ -D__WUPS__ $(MODE_FLAGS)
CXXFLAGS := $(CFLAGS) -std=gnu++20
ASFLAGS := -g $(ARCH)
LDFLAGS = -g $(ARCH) $(RPXSPECS) -Wl,-Map,$(notdir $*.map) $(WUPSSPECS)

ifeq ($(DEBUG),1)
CXXFLAGS += -DDEBUG -g
CFLAGS += -DDEBUG -g
endif

LIBS := -lwups -lwut
LIBDIRS := $(PORTLIBS) $(WUPS_ROOT) $(WUT_ROOT) $(WUMS_ROOT)

ifneq ($(BUILD),$(notdir $(CURDIR)))
export OUTPUT := $(CURDIR)/$(TARGET)
export TOPDIR := $(CURDIR)
export VPATH := $(foreach dir,$(SOURCES),$(CURDIR)/$(dir)) \
 $(foreach dir,$(DATA),$(CURDIR)/$(dir))
export DEPSDIR := $(CURDIR)/$(BUILD)
CFILES := $(foreach dir,$(SOURCES),$(notdir $(wildcard $(dir)/*.c)))
CPPFILES := $(foreach dir,$(SOURCES),$(notdir $(wildcard $(dir)/*.cpp)))
SFILES := $(foreach dir,$(SOURCES),$(notdir $(wildcard $(dir)/*.s)))
BINFILES := $(foreach dir,$(DATA),$(notdir $(wildcard $(dir)/*.*)))
export LD := $(CXX)
export OFILES_BIN := $(addsuffix .o,$(BINFILES))
export OFILES_SRC := $(CPPFILES:.cpp=.o) $(CFILES:.c=.o) $(SFILES:.s=.o)
export OFILES := $(OFILES_BIN) $(OFILES_SRC)
export HFILES_BIN := $(addsuffix .h,$(subst .,_,$(BINFILES)))
export INCLUDE := $(foreach dir,$(INCLUDES),-I$(CURDIR)/$(dir)) \
 $(foreach dir,$(LIBDIRS),-I$(dir)/include) \
 -I$(CURDIR)/$(BUILD)
export LIBPATHS := $(foreach dir,$(LIBDIRS),-L$(dir)/lib)
export CFLAGS CXXFLAGS ASFLAGS LDFLAGS LIBS TARGET BUILD

.PHONY: all menu always one releases clean $(BUILD)
all: releases

menu:
	@$(MAKE) --no-print-directory VARIANT=menu one

always:
	@$(MAKE) --no-print-directory VARIANT=always one

one: $(BUILD)

releases: menu always
	@mkdir -p $(CURDIR)/../releases
	@cp -f $(CURDIR)/rearsensorbar-menu.wps $(CURDIR)/../releases/ 2>/dev/null || cp -f rearsensorbar-menu.wps ../releases/
	@cp -f $(CURDIR)/rearsensorbar-always.wps $(CURDIR)/../releases/ 2>/dev/null || cp -f rearsensorbar-always.wps ../releases/

$(BUILD):
	@$(shell [ ! -d $(BUILD) ] && mkdir -p $(BUILD))
	@$(MAKE) --no-print-directory -C $(BUILD) -f $(CURDIR)/Makefile VARIANT=$(VARIANT)

clean:
	@rm -fr build-menu build-always build \
		rearsensorbar-menu.wps rearsensorbar-menu.elf \
		rearsensorbar-always.wps rearsensorbar-always.elf \
		consolesensorbar-menu.wps consolesensorbar-always.wps consolesensorbar.wps
else
.PHONY: all
DEPENDS := $(OFILES:.o=.d)
all : $(OUTPUT).wps
$(OUTPUT).wps : $(OUTPUT).elf
$(OUTPUT).elf : $(OFILES)
$(OFILES_SRC) : $(HFILES_BIN)
%.bin.o %_bin.h : %.bin
	@echo $(notdir $<)
	@$(bin2o)
-include $(DEPENDS)
endif
