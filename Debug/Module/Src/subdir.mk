################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Module/Src/buttons.c \
../Module/Src/debug_LED.c \
../Module/Src/module.c \
../Module/Src/out.c \
../Module/Src/spi_LED.c 

OBJS += \
./Module/Src/buttons.o \
./Module/Src/debug_LED.o \
./Module/Src/module.o \
./Module/Src/out.o \
./Module/Src/spi_LED.o 

C_DEPS += \
./Module/Src/buttons.d \
./Module/Src/debug_LED.d \
./Module/Src/module.d \
./Module/Src/out.d \
./Module/Src/spi_LED.d 


# Each subdirectory must supply rules for building sources it contributes
Module/Src/%.o Module/Src/%.su Module/Src/%.cyclo: ../Module/Src/%.c Module/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F215xx -c -I../Core/Inc -I"D:/One 4_0 beta/i-WorkSpase/fw-002-test/fw-002/Module/Inc" -I../FATFS/Target -I../FATFS/App -I../USB_DEVICE/App -I../USB_DEVICE/Target -I../Drivers/STM32F2xx_HAL_Driver/Inc -I../Drivers/STM32F2xx_HAL_Driver/Inc/Legacy -I../Middlewares/Third_Party/FatFs/src -I../Middlewares/Third_Party/FatFs/src/drivers -I../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc -I../Drivers/CMSIS/Device/ST/STM32F2xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Module-2f-Src

clean-Module-2f-Src:
	-$(RM) ./Module/Src/buttons.cyclo ./Module/Src/buttons.d ./Module/Src/buttons.o ./Module/Src/buttons.su ./Module/Src/debug_LED.cyclo ./Module/Src/debug_LED.d ./Module/Src/debug_LED.o ./Module/Src/debug_LED.su ./Module/Src/module.cyclo ./Module/Src/module.d ./Module/Src/module.o ./Module/Src/module.su ./Module/Src/out.cyclo ./Module/Src/out.d ./Module/Src/out.o ./Module/Src/out.su ./Module/Src/spi_LED.cyclo ./Module/Src/spi_LED.d ./Module/Src/spi_LED.o ./Module/Src/spi_LED.su

.PHONY: clean-Module-2f-Src

