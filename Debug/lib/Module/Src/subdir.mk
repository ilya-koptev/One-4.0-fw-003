################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../lib/Module/Src/buttons.c \
../lib/Module/Src/debug_LED.c \
../lib/Module/Src/module.c \
../lib/Module/Src/out.c \
../lib/Module/Src/spi_LED.c 

OBJS += \
./lib/Module/Src/buttons.o \
./lib/Module/Src/debug_LED.o \
./lib/Module/Src/module.o \
./lib/Module/Src/out.o \
./lib/Module/Src/spi_LED.o 

C_DEPS += \
./lib/Module/Src/buttons.d \
./lib/Module/Src/debug_LED.d \
./lib/Module/Src/module.d \
./lib/Module/Src/out.d \
./lib/Module/Src/spi_LED.d 


# Each subdirectory must supply rules for building sources it contributes
lib/Module/Src/%.o lib/Module/Src/%.su: ../lib/Module/Src/%.c lib/Module/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F215xx -c -I"D:/One 4_0 beta/i-WorkSpase/fw-002-test/fw-002/lib" -I../Core/Inc -I../FATFS/Target -I../FATFS/App -I../USB_DEVICE/App -I../USB_DEVICE/Target -I../Drivers/STM32F2xx_HAL_Driver/Inc -I../Drivers/STM32F2xx_HAL_Driver/Inc/Legacy -I../Middlewares/Third_Party/FatFs/src -I../Middlewares/Third_Party/FatFs/src/drivers -I../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc -I../Drivers/CMSIS/Device/ST/STM32F2xx/Include -I../Drivers/CMSIS/Include -I"D:/One 4_0 beta/i-WorkSpase/fw-002-test/fw-002/lib/Module" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-lib-2f-Module-2f-Src

clean-lib-2f-Module-2f-Src:
	-$(RM) ./lib/Module/Src/buttons.d ./lib/Module/Src/buttons.o ./lib/Module/Src/buttons.su ./lib/Module/Src/debug_LED.d ./lib/Module/Src/debug_LED.o ./lib/Module/Src/debug_LED.su ./lib/Module/Src/module.d ./lib/Module/Src/module.o ./lib/Module/Src/module.su ./lib/Module/Src/out.d ./lib/Module/Src/out.o ./lib/Module/Src/out.su ./lib/Module/Src/spi_LED.d ./lib/Module/Src/spi_LED.o ./lib/Module/Src/spi_LED.su

.PHONY: clean-lib-2f-Module-2f-Src

