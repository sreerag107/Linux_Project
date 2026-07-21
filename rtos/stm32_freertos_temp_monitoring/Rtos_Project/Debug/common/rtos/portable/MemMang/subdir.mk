################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../common/rtos/portable/MemMang/heap_4.c 

OBJS += \
./common/rtos/portable/MemMang/heap_4.o 

C_DEPS += \
./common/rtos/portable/MemMang/heap_4.d 


# Each subdirectory must supply rules for building sources it contributes
common/rtos/portable/MemMang/%.o common/rtos/portable/MemMang/%.su common/rtos/portable/MemMang/%.cyclo: ../common/rtos/portable/MemMang/%.c common/rtos/portable/MemMang/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I"/home/sreerag/STM32CubeIDE/workspace_1.19.0/Rtos/Rtos_Project/common/rtos/include" -I"/home/sreerag/STM32CubeIDE/workspace_1.19.0/Rtos/Rtos_Project/common/rtos/portable/GCC/ARM_CM4F" -I"/home/sreerag/STM32CubeIDE/workspace_1.19.0/Rtos/Rtos_Project/common/rtos/portable/MemMang" -I"/home/sreerag/STM32CubeIDE/workspace_1.19.0/Rtos/Rtos_Project/common/rtos" -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-common-2f-rtos-2f-portable-2f-MemMang

clean-common-2f-rtos-2f-portable-2f-MemMang:
	-$(RM) ./common/rtos/portable/MemMang/heap_4.cyclo ./common/rtos/portable/MemMang/heap_4.d ./common/rtos/portable/MemMang/heap_4.o ./common/rtos/portable/MemMang/heap_4.su

.PHONY: clean-common-2f-rtos-2f-portable-2f-MemMang

