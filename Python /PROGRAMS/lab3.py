
import numpy as np
import matplotlib.pyplot as plt

# Define x and y
x = np.linspace(-10, 10, 500)
y = x**4 + 5

# Plot the graph
plt.plot(x, y, label='y = x^4 + 5', color='blue')
plt.title('Graph of y = x^4 + 5')
plt.xlabel('x')
plt.ylabel('y')
plt.axhline(0, color='black', linewidth=0.5, linestyle='--')
plt.axvline(0, color='black', linewidth=0.5, linestyle='--')
plt.grid()
plt.legend()
plt.show()



## 2

import numpy as np
import matplotlib.pyplot as plt

# Define data
x = np.linspace(0, 10, 50)
y = np.sin(x)

# Plot normal graph
plt.figure(figsize=(10, 5))
plt.subplot(1, 2, 1)
plt.plot(x, y, label='Normal Graph', color='blue')
plt.title('Normal Graph')
plt.xlabel('x')
plt.ylabel('y')
plt.legend()
plt.grid()

# Plot stem graph
plt.subplot(1, 2, 2)
plt.stem(x, y, linefmt='red', markerfmt='ro', basefmt='black', use_line_collection=True)
plt.title('Stem Graph')
plt.xlabel('x')
plt.ylabel('y')
plt.grid()

plt.tight_layout()
plt.show()


##3 

import matplotlib.pyplot as plt

# Data
continents = ['Africa', 'Asia', 'Europe', 'North America', 'Oceania', 'South America', 'Soviet Union']
areas = [11.7, 10.4, 1.9, 9.4, 3.3, 6.9, 7.9]

# Plot bar chart
plt.bar(continents, areas, color='skyblue')
plt.title('Areas of Continents (in million square miles)')
plt.xlabel('Continents')
plt.ylabel('Area (million square miles)')
plt.xticks(rotation=45)
plt.grid(axis='y', linestyle='--', linewidth=0.5)
plt.show()


##d 
import numpy as np
import matplotlib.pyplot as plt

# Define time and input signal
t = np.linspace(0, 2 * np.pi, 500)
input_signal = np.sin(t)
output_signal = np.abs(np.sin(t))

# Plot input and output signals
plt.plot(t, input_signal, label='Input Signal (sin(t))', color='blue')
plt.plot(t, output_signal, label='Output Signal (Full-Wave Rectified)', color='red', linestyle='--')
plt.title('Full-Wave Rectifier Input and Output')
plt.xlabel('Time')
plt.ylabel('Amplitude')
plt.legend()
plt.grid()
plt.show()


##e

import matplotlib.pyplot as plt

# Data
heights = ['135-140', '140-145', '145-150', '150-155']
students = [4, 12, 16, 8]

# Plot histogram
plt.bar(heights, students, color='purple', width=0.6)
plt.title('Histogram of Student Heights')
plt.xlabel('Height (cm)')
plt.ylabel('Number of Students')
plt.grid(axis='y', linestyle='--', linewidth=0.5)
plt.show()


## 6 a
from math import comb

n = 6
p = 0.25
k = 4

# Calculate P(X = 4)
P_X_4 = comb(n, k) * (p**k) * ((1-p)**(n-k))
print(f"Probability of exactly 4 successes: {P_X_4}")


## 2

# Calculate P(X >= 1)
P_X_0 = comb(n, 0) * (p**0) * ((1-p)**n)
P_X_ge_1 = 1 - P_X_0
print(f"Probability of at least one success: {P_X_ge_1}")

##3

from math import exp, factorial

lam = 3.4
k = 6

# Calculate P(X = 6)
P_X_6 = (lam**k * exp(-lam)) / factorial(k)
print(f"P(X = 6) for Poisson distribution: {P_X_6}")
