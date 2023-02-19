# ******************************************************************************************
#   Filename    : Makefile
#
#   Author      : Chalandi Amine
#
#   Owner       : Chalandi Amine
#
#   Date        : 22.11.2022
#
#   Description : Build system
#
# ******************************************************************************************

############################################################################################
# Defines
############################################################################################

HW_TARGET               = WCH_V307_RISC-V
PRJ_NAME                = BareMetal_$(HW_TARGET)
OUTPUT_DIR              = ../Output
OBJ_DIR                 = $(OUTPUT_DIR)/Obj
LD_SCRIPT               = $(SRC_DIR)/Memory_Map.ld
SRC_DIR                 = ../Code
ERR_MSG_FORMATER_SCRIPT = ../Tools/Scripts/CompilerErrorFormater.py

############################################################################################
# Toolchain
############################################################################################

TOOLCHAIN = riscv-none-embed
AS        = $(TOOLCHAIN)-g++
CC        = $(TOOLCHAIN)-g++
CPP       = $(TOOLCHAIN)-g++
LD        = $(TOOLCHAIN)-g++
OBJDUMP   = $(TOOLCHAIN)-objdump
OBJCOPY   = $(TOOLCHAIN)-objcopy
READELF   = $(TOOLCHAIN)-readelf

PYTHON = python

############################################################################################
# Optimization Compiler flags
############################################################################################

OPT_MODIFIED_O2 = -O2                               \
                  -fno-reorder-blocks-and-partition \
                  -fno-reorder-functions

NO_OPT = -O0

OPT = $(NO_OPT)

############################################################################################
# GCC Compiler verbose flags
############################################################################################

VERBOSE_GCC = -frecord-gcc-switches -fverbose-asm

############################################################################################
# Target's Compiler flags
############################################################################################

ARCH = -march=rv32imafc -mabi=ilp32f -msmall-data-limit=0 -falign-functions=4

############################################################################################
# C Compiler flags
############################################################################################

COPS  = $(OPT)                                        \
        $(ARCH)                                       \
        -ffast-math                                   \
        -Wa,-adhln=$(OBJ_DIR)/$(basename $(@F)).lst   \
        -g3                                           \
        -x c                                          \
        -std=c99                                      \
        -Wall                                         \
        -Wextra                                       \
        -fomit-frame-pointer                          \
        -gdwarf-2                                     \
        -fsingle-precision-constant

############################################################################################
# C++ Compiler flags
############################################################################################

CPPOPS  = $(OPT)                                        \
          $(ARCH)                                       \
          -ffast-math                                   \
          -Wa,-adhln=$(OBJ_DIR)/$(basename $(@F)).lst   \
          -g3                                           \
          -Wall                                         \
          -Wextra                                       \
          -fomit-frame-pointer                          \
          -gdwarf-2                                     \
          -fno-exceptions                               \
          -x c++                                        \
          -fno-rtti                                     \
          -fno-use-cxa-atexit                           \
          -fno-nonansi-builtins                         \
          -fno-threadsafe-statics                       \
          -fno-enforce-eh-specs                         \
          -ftemplate-depth=128                          \
          -Wzero-as-null-pointer-constant               \
          -fsingle-precision-constant

############################################################################################
# Assembler flags
############################################################################################

ifeq ($(AS), $(TOOLCHAIN)-as)
ASOPS =  -march=rv32imafc -alh
else
ASOPS = $(OPT)                                        \
        $(ARCH)                                       \
        -ffast-math                                   \
        -Wa,-adhln=$(OBJ_DIR)/$(basename $(@F)).lst   \
        -g3                                           \
        -Wall                                         \
        -Wextra                                       \
        -fomit-frame-pointer                          \
        -gdwarf-2                                     \
        -fno-exceptions                               \
        -x assembler                                  \
        -fno-rtti                                     \
        -fno-use-cxa-atexit                           \
        -fno-nonansi-builtins                         \
        -fno-threadsafe-statics                       \
        -fno-enforce-eh-specs                         \
        -ftemplate-depth=128                          \
        -Wzero-as-null-pointer-constant
endif
############################################################################################
# Linker flags
############################################################################################

ifeq ($(LD), $(TOOLCHAIN)-ld)
  LOPS = -nostartfiles                          \
         -nostdlib                              \
         --print-memory-usage                   \
         --print-map                            \
         -dT $(LD_SCRIPT)                       \
         -Map=$(OUTPUT_DIR)/$(PRJ_NAME).map     

else
  LOPS = -nostartfiles                          \
         -nostdlib                              \
         $(ARCH)                                \
         -ffast-math                            \
         -Wl,--print-memory-usage               \
         -Wl,--print-map                        \
         -Wl,-dT $(LD_SCRIPT)                   \
         -Wl,-Map=$(OUTPUT_DIR)/$(PRJ_NAME).map \
         --specs=nano.specs                     \
         --specs=nosys.specs
endif

############################################################################################
# Source Files
############################################################################################
OSEK_SRC_FILES := $(SRC_DIR)/OSEK/HwPlatform/RISC-V/OsSwClz.s          \
                  $(SRC_DIR)/OSEK/HwPlatform/RISC-V/OsAsm.s            \
                  $(SRC_DIR)/OSEK/HwPlatform/RISC-V/OsHwSchedPrio.s    \
                  $(SRC_DIR)/OSEK/HwPlatform/RISC-V/OsHwPltfm.c        \
                  $(SRC_DIR)/OSEK/HwPlatform/RISC-V/OsIntVect.asm      \
                  $(SRC_DIR)/OSEK/OsAlarm.c                            \
                  $(SRC_DIR)/OSEK/OsCore.c                             \
                  $(SRC_DIR)/OSEK/OsEvt.c                              \
                  $(SRC_DIR)/OSEK/OsSched.c                            \
                  $(SRC_DIR)/OSEK/OsTask.c                             \
                  $(SRC_DIR)/OSEK/OsTcb.c

SRC_FILES := $(SRC_DIR)/Appli/main.c         \
             $(SRC_DIR)/Mcal/Mcu.c           \
             $(SRC_DIR)/Mcal/SysTick.c       \
             $(SRC_DIR)/Startup/boot.s       \
             $(SRC_DIR)/Startup/Startup.c    \
             $(SRC_DIR)/Appli/tasks.c        \
             $(OSEK_SRC_FILES)

############################################################################################
# Include Paths
############################################################################################
OSEK_INC_FILES := $(SRC_DIR)/OSEK/HwPlatform/RISC-V     \
                  $(SRC_DIR)/OSEK

INC_FILES := $(SRC_DIR)         \
             $(SRC_DIR)/Appli   \
             $(SRC_DIR)/Mcal    \
             $(SRC_DIR)/Startup \
             $(OSEK_INC_FILES)   

#####################################################################################
# Preprocessing flag
#####################################################################################
PFLAGS       := -E
FILES_i      := $(addprefix $(OBJ_PATH)/, $(notdir $(addsuffix .i, $(basename $(SRC_FILES)))))

############################################################################################
# Rules
############################################################################################

VPATH := $(subst \,/,$(sort $(dir $(SRC_FILES)) $(OBJ_DIR)))

FILES_O := $(addprefix $(OBJ_DIR)/, $(notdir $(addsuffix .o, $(basename $(SRC_FILES)))))


ifeq ($(MAKECMDGOALS),build)
-include $(subst .o,.d,$(FILES_O))
endif

build : $(OUTPUT_DIR)/$(PRJ_NAME).elf

all : $(OUTPUT_DIR)/$(PRJ_NAME).elf

.PHONY : clean
clean :
	@-rm -rf $(OUTPUT_DIR)  2>/dev/null || true
	@-mkdir -p $(subst \,/,$(OBJ_DIR))


$(OBJ_DIR)/%.o : %.c
	@-echo +++ compile: $(subst \,/,$<) to $(subst \,/,$@)
	@-$(CC) $(COPS) $(addprefix -I, $(INC_FILES)) -c $< -o $(OBJ_DIR)/$(basename $(@F)).o 2> $(OBJ_DIR)/$(basename $(@F)).err
	@-$(PYTHON) $(ERR_MSG_FORMATER_SCRIPT) $(OBJ_DIR)/$(basename $(@F)).err -COLOR


ifeq ($(AS), $(TOOLCHAIN)-as)
$(OBJ_DIR)/%.o : %.s
	@-echo +++ compile: $(subst \,/,$<) to $(subst \,/,$@)
	@$(AS) $(ASOPS) $< -o $(OBJ_DIR)/$(basename $(@F)).o 2> $(OBJ_DIR)/$(basename $(@F)).err >$(OBJ_DIR)/$(basename $(@F)).lst
	@-$(PYTHON) $(ERR_MSG_FORMATER_SCRIPT) $(OBJ_DIR)/$(basename $(@F)).err -COLOR

$(OBJ_DIR)/%.o : %.asm
	@-echo +++ compile: $(subst \,/,$<) to $(subst \,/,$@)
	@$(CC) -E -P $(addprefix -I, $(INC_FILES)) -x c $< > $(OBJ_DIR)/$(basename $(@F)).asm.pre
	@$(AS) $(ASOPS) $(OBJ_DIR)/$(basename $(@F)).asm.pre -o $(OBJ_DIR)/$(basename $(@F)).o 2> $(OBJ_DIR)/$(basename $(@F)).err >$(OBJ_DIR)/$(basename $(@F)).lst
	@-$(PYTHON) $(ERR_MSG_FORMATER_SCRIPT) $(OBJ_DIR)/$(basename $(@F)).err -COLOR
else
$(OBJ_DIR)/%.o : %.s
	@-echo +++ compile: $(subst \,/,$<) to $(subst \,/,$@)
	@-$(CC) $(ASOPS) $(addprefix -I, $(INC_FILES)) -c $< -o $(OBJ_DIR)/$(basename $(@F)).o 2> $(OBJ_DIR)/$(basename $(@F)).err
	@-$(PYTHON) $(ERR_MSG_FORMATER_SCRIPT) $(OBJ_DIR)/$(basename $(@F)).err -COLOR

$(OBJ_DIR)/%.o : %.asm
	@-echo +++ compile: $(subst \,/,$<) to $(subst \,/,$@)
	@$(CC) -E -P $(addprefix -I, $(INC_FILES)) -x c $< > $(OBJ_DIR)/$(basename $(@F)).asm.pre
	@-$(CC) $(ASOPS) $(addprefix -I, $(INC_FILES)) -c $(OBJ_DIR)/$(basename $(@F)).asm.pre -o $(OBJ_DIR)/$(basename $(@F)).o 2> $(OBJ_DIR)/$(basename $(@F)).err
	@-$(PYTHON) $(ERR_MSG_FORMATER_SCRIPT) $(OBJ_DIR)/$(basename $(@F)).err -COLOR
endif


$(OBJ_DIR)/%.o : %.cpp
	@-echo +++ compile : $(subst \,/,$<) to $(subst \,/,$@)
	@$(CPP) $(CPPOPS) $(addprefix -I, $(INC_FILES)) -c $< -o $(OBJ_DIR)/$(basename $(@F)).o 2> $(OBJ_DIR)/$(basename $(@F)).err
	@-$(PYTHON) $(ERR_MSG_FORMATER_SCRIPT) $(OBJ_DIR)/$(basename $(@F)).err -COLOR


$(OUTPUT_DIR)/$(PRJ_NAME).elf : $(FILES_O) $(LD_SCRIPT)
	@-echo +++ link : $(subst \,/,$@)
	@$(LD) $(LOPS) $(FILES_O) -o $(OUTPUT_DIR)/$(PRJ_NAME).elf
	@-echo +++ generate : $(OUTPUT_DIR)/$(PRJ_NAME).list.text
	@$(OBJDUMP) -d --visualize-jumps --wide $(OUTPUT_DIR)/$(PRJ_NAME).elf > $(OUTPUT_DIR)/$(PRJ_NAME).list.text
	@-echo +++ generate : $(OUTPUT_DIR)/$(PRJ_NAME).list.all
	@$(OBJDUMP) -D --visualize-jumps --wide $(OUTPUT_DIR)/$(PRJ_NAME).elf > $(OUTPUT_DIR)/$(PRJ_NAME).list.all
	@-echo +++ generate : $(OUTPUT_DIR)/$(PRJ_NAME).list.text.pure
	@$(OBJDUMP) -d --visualize-jumps --wide --disassembler-options=numeric,no-aliases $(OUTPUT_DIR)/$(PRJ_NAME).elf > $(OUTPUT_DIR)/$(PRJ_NAME).list.text.pure
	@-echo +++ generate : $(OUTPUT_DIR)/$(PRJ_NAME).hex
	@$(OBJCOPY) $(OUTPUT_DIR)/$(PRJ_NAME).elf -O ihex $(OUTPUT_DIR)/$(PRJ_NAME).hex
	@-echo +++ generate : $(OUTPUT_DIR)/$(PRJ_NAME).readelf
	@$(READELF) --wide -a $(OUTPUT_DIR)/$(PRJ_NAME).elf > $(OUTPUT_DIR)/$(PRJ_NAME).readelf

