TOP      := .


include $(TOP)/common.mk

.PHONY: all clean debug

# subdirs_exclude: 被忽略的文件夹列表，即不会进入这个文件夹执行递归make
subdirs_exclude = resource

subdirs_all := $(sort $(subst /,,$(dir $(wildcard */*))))
subdirs = $(filter-out $(subdirs_exclude), $(subdirs_all))

all:: $(subdirs)
	@for subdir in $(subdirs); do \
		$(MAKE) -C $$subdir; \
	done

debug::
	@echo subdirs_all: $(subdirs_all)
	@echo subdirs_exclude: $(subdirs_exclude)
	@echo subdirs: $(subdirs)

clean::
	@for subdir in $(subdirs); do \
		$(MAKE) -C $$subdir clean; \
	done
