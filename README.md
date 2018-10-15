# velocity_distribution
This section generates a maxwell velocity distribution for counter-streaming beams using acceptance-rejection method. 
Necessary modules for plotting are matplotlib and pandas.
type
```
./run.sh
```
in the terminal to build, run and plot the distribution function for the default values
```
v_th = 1.;
L = 1000;
n_0 = 200000;
v_b = 5.;
```
The distribution function for the default values would be
![Maxwellian for two counter-streaming beams](/images/f-v.png)

type
```
./clean.sh
```
to delete all output files, .png, objects, executables.
