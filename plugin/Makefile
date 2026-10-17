# Wii U Sensor bar Power Fix — AlwaysBar + MenuBar

ifeq ($(strip $(DEVKITPRO)),)
$(error "Please set DEVKITPRO. export DEVKITPRO=/opt/devkitpro")
endif

VARIANT ?= alwaysbar

ifeq ($(VARIANT),alwaysbar)
  TARGET := sensorbarfix-alwaysbar
  BUILD := build-alwaysbar
  MODE_FLAGS := -DSENSOR_BAR_FIX_ALWAYSBAR=1
else
  TARGET := sensorbarfix-menubar
  BUILD := build-menubar
  MODE_FLAGS := -DSENSOR_BAR_FIX_ALWAYSBAR=0
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

.PHONY: all alwaysbar menubar one releases clean $(BUILD)
all: releases

alwaysbar:
	@$(MAKE) --no-print-directory VARIANT=alwaysbar one

menubar:
	@$(MAKE) --no-print-directory VARIANT=menubar one

one: $(BUILD)

releases: alwaysbar menubar
	@mkdir -p $(CURDIR)/../releases
	@cp -f $(CURDIR)/sensorbarfix-alwaysbar.wps $(CURDIR)/../releases/ 2>/dev/null || cp -f sensorbarfix-alwaysbar.wps ../releases/
	@cp -f $(CURDIR)/sensorbarfix-menubar.wps $(CURDIR)/../releases/ 2>/dev/null || cp -f sensorbarfix-menubar.wps ../releases/

$(BUILD):
	@$(shell [ ! -d $(BUILD) ] && mkdir -p $(BUILD))
	@$(MAKE) --no-print-directory -C $(BUILD) -f $(CURDIR)/Makefile VARIANT=$(VARIANT)

clean:
	@rm -fr build-alwaysbar build-menubar build-menu build-always \
		sensorbarfix-alwaysbar.wps sensorbarfix-alwaysbar.elf \
		sensorbarfix-menubar.wps sensorbarfix-menubar.elf \
		rearsensorbar-*.wps consolesensorbar-*.wps
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
