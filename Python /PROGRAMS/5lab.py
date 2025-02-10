import numpy as np

# Population data from the table
population = np.array([4779736, 710231, 6392017, 2915918, 37253956, 5029196, 3574097, 897934])

# Compute mean, median, and variance
mean_population = np.mean(population)
median_population = np.median(population)
variance_population = np.var(population, ddof=0)  # Population variance

# Display results
print(f"Mean Population: {mean_population}")
print(f"Median Population: {median_population}")
print(f"Variance of Population: {variance_population}")




import numpy as np

# Given class intervals and their frequencies
class_intervals = [(0,10), (10,20), (20,30), (30,40), (40,50), (50,60), (60,70), (70,80)]
frequencies = np.array([5, 10, 20, 40, 30, 20, 10, 5])

# Compute class midpoints
midpoints = np.array([(a + b) / 2 for a, b in class_intervals])

# Compute mean
mean = np.sum(midpoints * frequencies) / np.sum(frequencies)

# Compute variance
variance = np.sum(frequencies * (midpoints - mean) ** 2) / np.sum(frequencies)

# Compute standard deviation
std_dev = np.sqrt(variance)

# Compute coefficient of variation (C.V.)
cv = (std_dev / mean) * 100

# Display results
print(f"Mean: {mean}")
print(f"Standard Deviation (S.D.): {std_dev}")
print(f"Coefficient of Variation (C.V.): {cv}%")
