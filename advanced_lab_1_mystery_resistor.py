import numpy as np
import matplotlib.pyplot as plt

v_in=1023 #input voltage of 5 volts
r_ref=1000 # reference resistor of 1000 ohms

mystery = 476

r_mys=np.linspace(0,10000,1000)
v_out=(r_mys/(r_ref+r_mys))*v_in

fig, ax = plt.subplots()

ax.plot(r_mys, v_out, linewidth=2.0)
ax.set_xlabel('Mystery Resistance [ohms]')
ax.set_ylabel('Digital Output Voltage')
ax.set_title('Voltage as a Function of Resistance in a Parallel Circuit')
ax.grid()
# This line adds a circular 'o' marker at the specialPoint values for time and position.
ax.plot(r_mys[mystery], v_out[mystery],'o', color = 'tab:blue')


plt.annotate("Mystery Resistance at \n Measured Voltage", # this is the text
                  xy=(r_mys[476], v_out[476]), # these are the coordinates to position the label
                  textcoords="offset points", # how to position the text
                  xytext=(30,-50), # distance from text to points (x,y)
                  ha='center',
                  va='bottom',
                  bbox=dict(boxstyle='round,pad=0.5', fc='white', alpha=0.2),
                  arrowprops=dict(arrowstyle = '-|>', connectionstyle='arc3, rad=0'))

plt.show()
