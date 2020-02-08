################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/class_example.cpp \
../src/functions.cpp \
../src/main.cpp 

OBJS += \
./src/class_example.o \
./src/functions.o \
./src/main.o 

CPP_DEPS += \
./src/class_example.d \
./src/functions.d \
./src/main.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"/media/hossam/professional/computer_programming/workspace/C-C++/cpp-review/inc" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


