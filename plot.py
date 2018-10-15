import pandas as pd
import matplotlib.pyplot as plt

data = pd.read_csv("fv.out")

f=list(data.f)
v=list(data.v)
x=list(data.x)

plt.plot(v,f,".")
plt.title("Vel_Dist")

plt.xlabel("velocity")
plt.ylabel("f(v)")
plt.show()

