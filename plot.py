import pandas as pd
import matplotlib.pyplot as plt

data = pd.read_csv("fv.out")

f=list(data.f)
v=list(data.v)

plt.plot(v,f,".")
plt.title("Velocity Distribution")

plt.xlabel("velocity")
plt.ylabel("f(v)")
plt.show()
plot.savefig("f-v.png")

