
MAIN := Examples/example.c
TARGET := $(notdir $(basename $(MAIN)))

c_srcs := $(shell find src -name "*.c")
c_objs := $(patsubst src/%.c,objs/%.o,$(c_srcs))

include_dirs := include

I_options := $(include_dirs:%=-I%)

compile_options := -g $(I_options)
linking_options := 


# Compile TARGET
objs/$(TARGET).o : $(MAIN) include/Exercise.h
	@echo [INFO]: Compile $^ to $@
	@mkdir -p $(dir $@)
	@gcc -c $< -o $@ $(compile_options)


workspace/$(TARGET) : objs/$(TARGET).o 
	@echo [INFO]: Linking $^ to $@
	@mkdir -p $(dir $@)
	@gcc $^ -o $@ $(linking_options)

run : workspace/$(TARGET)
	@./$<


debug :
	@echo $(TARGET)

clean :
	@rm -rf objs lib workspace/$(TARGET)

.PHONY : debug clean run