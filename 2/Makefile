#
#
#

.PHONY: all clean debug indent

# sources_exclude: 忽略的源文件列表
sources_exclude =
# objects_exclude: 忽略的目标文件列表
objects_exclude =
# programs_exclude: 忽略的可执行文件列表
programs_exclude =

# 如果一个源文件添加到了$(sources_exclude)变量中，那么它对应的目标文件和最终的可执行文件会被自动添加到$(objects_exclude)和$(programs_exclude)中

sources_all = $(wildcard *.cpp)
sources = $(filter-out $(sources_exclude), $(sources_all))

objects_all = $(patsubst %.cpp, %.o, $(sources))
objects += $(filter-out $(objects_exclude), $(objects_all))

programs_all = $(patsubst %.o, %, $(objects))
programs += $(filter-out $(programs_exclude), $(programs_all))


all:: $(programs)

#   Compile C++ files, and create appropriate .d files for each of them.
% : %.cpp
	@$(COMPILECXX) -o $@ $< $(CFLAGS) $(CV_CFLAGS) $(CV_LIBS) 

#   Compile C files, and create appropriate .d files for each of them.
% : %.c
	@$(COMPILEC) -o $@ $< $(CFLAGS) $(CV_CFLAGS) $(CV_LIBS) 

debug::
	@echo sources_all: $(sources_all)
	@echo sources_exclude: $(sources_exclude)
	@echo sources: $(sources)
	@echo objects_all: $(objects_all)
	@echo objects_exclude: $(objects_exclude)
	@echo objects: $(objects)
	@echo programs_all: $(programs_all)
	@echo programs_exclude: $(programs_exclude)
	@echo programs: $(programs)

clean::
	rm -f $(programs_all) $(objects_all)

indent::
	@set -e; for file in $(wildcard *.c *.cpp *.h); do \
		echo "indenting $$file"; \
		indent -npro -kr -i4 -ts4 -sob -l80 -ss -ncs -cp1 $$file; \
		#indent -gnu -nut -cli2 -ss -v -i2 $$file; \
		rm -f $$file~; \
	done
