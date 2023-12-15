################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Middlewares/Third_Party/FatFs/src/drivers/sd_diskio.c 

OBJS += \
./Middlewares/Third_Party/FatFs/src/drivers/sd_diskio.o 

C_DEPS += \
./Middlewares/Third_Party/FatFs/src/drivers/sd_diskio.d 


# Each subdirectory must supply rules for building sources it contributes
Middlewares/Third_Party/FatFs/src/drivers/%.o Middlewares/Third_Party/FatFs/src/drivers/%.su Middlewares/Third_Party/FatFs/src/drivers/%.cyclo: ../Middlewares/Third_Party/FatFs/src/drivers/%.c Middlewares/Third_Party/FatFs/src/drivers/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F215xx -c -I../Core/Inc -I"D:/One 4_0 beta/i-WorkSpase/fw-002-test/fw-002/Module/Inc" -I../FATFS/Target -I../FATFS/App -I../USB_DEVICE/App -I../USB_DEVICE/Target -I../Drivers/STM32F2xx_HAL_Driver/Inc -I../Drivers/STM32F2xx_HAL_Driver/Inc/Legacy -I../Middlewares/Third_Party/FatFs/src -I../Middlewares/Third_Party/FatFs/src/drivers -I../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc -I../Drivers/CMSIS/Device/ST/STM32F2xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Middlewares-2f-Third_Party-2f-FatFs-2f-src-2f-drivers

clean-Middlewares-2f-Third_Party-2f-FatFs-2f-src-2f-drivers:
	-$(RM) ./Middlewares/Third_Party/FatFs/src/drivers/sd_diskio.cyclo ./Middlewares/Third_Party/FatFs/src/drivers/sd_diskio.d ./Middlewares/Third_Party/FatFs/src/drivers/sd_diskio.o ./Middlewares/Third_Party/FatFs/src/drivers/sd_diskio.su

.PHONY: clean-Middlewares-2f-Third_Party-2f-FatFs-2f-src-2f-drivers

