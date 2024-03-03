import numpy as np  
import random  
  
# 设定种子值  
np_seed = 42  
random_seed = 42  
  
# 使用numpy生成随机数  
np.random.seed(np_seed)  
x = np.random.randint(0, 10, size=5)  
print("Numpy随机数:", x)  
  
# 使用random模块生成随机数  
random.seed(random_seed)  
y = random.randint(0, 10)  
print("Python随机数:", y)