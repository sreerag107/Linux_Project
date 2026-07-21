################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../common/rtos/croutine.c \
../common/rtos/event_groups.c \
../common/rtos/list.c \
../common/rtos/queue.c \
../common/rtos/stream_buffer.c \
../common/rtos/tasks.c \
../common/rtos/timers.c 

OBJS += \
./common/rtos/croutine.o \
./common/rtos/event_groups.o \
./common/rtos/list.o \
./common/rtos/queue.o \
./common/rtos/stream_buffer.o \
./common/rtos/tasks.o \
./common/rtos/timers.o 

C_DEPS += \
./common/rtos/croutine.d \
./common/rtos/event_groups.d \
./common/rtos/list.d \
./common/rtos/queue.d \
./common/rtos/stream_buffer.d \
./common/rtos/tasks.d \
./common/rtos/timers.d 


# Each subdirectory must supply rules for building sources it contributes
common/rtos/%.o common/rtos/%.su common/rtos/%.cyclo: ../common/rtos/%.c common/rtos/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I"/home/sreerag/STM32CubeIDE/workspace_1.19.0/Rtos/Rtos_Project/common/rtos/include" -I"/home/sreerag/STM32CubeIDE/workspace_1.19.0/Rtos/Rtos_Project/common/rtos/portable/GCC/ARM_CM4F" -I"/home/sreerag/STM32CubeIDE/workspace_1.19.0/Rtos/Rtos_Project/common/rtos/portable/MemMang" -I"/home/sreerag/STM32CubeIDE/workspace_1.19.0/Rtos/Rtos_Project/common/rtos" -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-common-2f-rtos

clean-common-2f-rtos:
	-$(RM) ./common/rtos/croutine.cyclo ./common/rtos/croutine.d ./common/rtos/croutine.o ./common/rtos/croutine.su ./common/rtos/event_groups.cyclo ./common/rtos/event_groups.d ./common/rtos/event_groups.o ./common/rtos/event_groups.su ./common/rtos/list.cyclo ./common/rtos/list.d ./common/rtos/list.o ./common/rtos/list.su ./common/rtos/queue.cyclo ./common/rtos/queue.d ./common/rtos/queue.o ./common/rtos/queue.su ./common/rtos/stream_buffer.cyclo ./common/rtos/stream_buffer.d ./common/rtos/stream_buffer.o ./common/rtos/stream_buffer.su ./common/rtos/tasks.cyclo ./common/rtos/tasks.d ./common/rtos/tasks.o ./common/rtos/tasks.su ./common/rtos/timers.cyclo ./common/rtos/timers.d ./common/rtos/timers.o ./common/rtos/timers.su

.PHONY: clean-common-2f-rtos

