# src = $(wildcard *%.c)
# obj = $(patsubst %.c ,%.o, $(src))

# ALL:a.out
# myargs: -Wall -g

# $(obj):%.o:%.c
# 	gcc -c $< -o $@ $(myargs)

# a.out: $(obj)
# 	gcc $^ -o $@ $(myargs)

# clean:
# 	-rm -rf $(obj) a.out

# .PHONY:ALL clean
src = $(wildcard *%.c)  
obj = $(patsubst %.c, %.o, $(src))  
  
ALL:a.out  
myargs: -Wall -g  
  
$(obj):%.o:%.c  
	gcc -c $< -o $@ $(myargs)  
  
a.out: $(obj)  
	gcc $^ -o $@ $(myargs)  
  
clean:  
	-rm -rf $(obj) a.out  
  
.PHONY:ALL clean