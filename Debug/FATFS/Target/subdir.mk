################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../FATFS/Target/bsp_driver_sd.c 

OBJS += \
./FATFS/Target/bsp_driver_sd.o 

C_DEPS += \
./FATFS/Target/bsp_driver_sd.d 


# Each subdirectory must supply rules for building sources it contributes
FATFS/Target/%.o FATFS/Target/%.su FATFS/Target/%.cyclo: ../FATFS/Target/%.c FATFS/Target/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F215xx -c -I../Core/Inc -I"D:/One 4_0 beta/i-WorkSpase/fw-002-test/fw-002/Module/Inc" -I../FATFS/Target -I../FATFS/App -I../USB_DEVICE/App -I../USB_DEVICE/Target -I../Drivers/STM32F2xx_HAL_Driver/Inc -I../Drivers/STM32F2xx_HAL_Driver/Inc/Legacy -I../Middlewares/Third_Party/FatFs/src -I../Middlewares/Third_Party/FatFs/src/drivers -I../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc -I../Drivers/CMSIS/Device/ST/STM32F2xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-FATFS-2f-Target

clean-FATFS-2f-Target:
	-$(RM) ./FATFS/Target/bsp_driver_sd.cyclo ./FATFS/Target/bsp_driver_sd.d ./FATFS/Target/bsp_driver_sd.o ./FATFS/Target/bsp_driver_sd.su

.PHONY: clean-FATFS-2f-Target

