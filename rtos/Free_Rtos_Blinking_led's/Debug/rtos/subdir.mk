################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../rtos/croutine.c \
../rtos/event_groups.c \
../rtos/list.c \
../rtos/queue.c \
../rtos/stream_buffer.c \
../rtos/tasks.c \
../rtos/timers.c 

OBJS += \
./rtos/croutine.o \
./rtos/event_groups.o \
./rtos/list.o \
./rtos/queue.o \
./rtos/stream_buffer.o \
./rtos/tasks.o \
./rtos/timers.o 

C_DEPS += \
./rtos/croutine.d \
./rtos/event_groups.d \
./rtos/list.d \
./rtos/queue.d \
./rtos/stream_buffer.d \
./rtos/tasks.d \
./rtos/timers.d 


# Each subdirectory must supply rules for building sources it contributes
rtos/%.o rtos/%.su rtos/%.cyclo: ../rtos/%.c rtos/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../USB_HOST/App -I"/home/sreerag/STM32CubeIDE/workspace_1.19.0/Rtos/Hello_world/rtos" -I"/home/sreerag/STM32CubeIDE/workspace_1.19.0/Rtos/Hello_world/rtos/include" -I"/home/sreerag/STM32CubeIDE/workspace_1.19.0/Rtos/Hello_world/rtos/portable" -I"/home/sreerag/STM32CubeIDE/workspace_1.19.0/Rtos/Hello_world/rtos/portable/GCC/ARM_CM4F" -I../USB_HOST/Target -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Middlewares/ST/STM32_USB_Host_Library/Core/Inc -I../Middlewares/ST/STM32_USB_Host_Library/Class/CDC/Inc -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-rtos

clean-rtos:
	-$(RM) ./rtos/croutine.cyclo ./rtos/croutine.d ./rtos/croutine.o ./rtos/croutine.su ./rtos/event_groups.cyclo ./rtos/event_groups.d ./rtos/event_groups.o ./rtos/event_groups.su ./rtos/list.cyclo ./rtos/list.d ./rtos/list.o ./rtos/list.su ./rtos/queue.cyclo ./rtos/queue.d ./rtos/queue.o ./rtos/queue.su ./rtos/stream_buffer.cyclo ./rtos/stream_buffer.d ./rtos/stream_buffer.o ./rtos/stream_buffer.su ./rtos/tasks.cyclo ./rtos/tasks.d ./rtos/tasks.o ./rtos/tasks.su ./rtos/timers.cyclo ./rtos/timers.d ./rtos/timers.o ./rtos/timers.su

.PHONY: clean-rtos

