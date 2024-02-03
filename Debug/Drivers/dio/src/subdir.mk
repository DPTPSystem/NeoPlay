################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/dio/src/dio_drv.c 

OBJS += \
./Drivers/dio/src/dio_drv.o 

C_DEPS += \
./Drivers/dio/src/dio_drv.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/dio/src/%.o Drivers/dio/src/%.su Drivers/dio/src/%.cyclo: ../Drivers/dio/src/%.c Drivers/dio/src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Middlewares/Third_Party/FatFs/src -I../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../Drivers/dio/inc -I../modules/interfaces/inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-dio-2f-src

clean-Drivers-2f-dio-2f-src:
	-$(RM) ./Drivers/dio/src/dio_drv.cyclo ./Drivers/dio/src/dio_drv.d ./Drivers/dio/src/dio_drv.o ./Drivers/dio/src/dio_drv.su

.PHONY: clean-Drivers-2f-dio-2f-src

