import numpy as np
from scipy.stats import chi2_contingency

# Observed data from the table
observed = np.array([
    [60, 54, 46, 41],  # Female
    [40, 44, 53, 57]   # Male
])

# Perform the Chi-Square test
chi2_stat, p_value, dof, expected = chi2_contingency(observed)

# Critical value at 5% significance level for df = 3
critical_value = 7.815

# Display results
print(f"Chi-Square Statistic: {chi2_stat:.4f}")
print(f"P-Value: {p_value:.4f}")
print(f"Degrees of Freedom: {dof}")
print(f"Critical Value (5% significance level): {critical_value}")

# Decision
if chi2_stat > critical_value or p_value < 0.05:
    print("Conclusion: Reject the null hypothesis. Gender and education level are dependent.")
else:
    print("Conclusion: Fail to reject the null hypothesis. Gender and education level are independent.")











import scipy.stats as stats

# Given data
sample_mean = 22
pop_mean = 20
sample_sd = 3
n = 16
alpha = 0.05

# Calculate t-statistic
t_statistic = (sample_mean - pop_mean) / (sample_sd / (n ** 0.5))

# Calculate p-value (two-tailed test)
p_value = 2 * (1 - stats.t.cdf(abs(t_statistic), df=n-1))

# Critical t-value for 95% confidence level (two-tailed test)
t_critical = stats.t.ppf(1 - alpha/2, df=n-1)

# Display results
print(f"T-Statistic: {t_statistic:.4f}")
print(f"P-Value: {p_value:.4f}")
print(f"Critical T-Value: ±{t_critical:.4f}")

# Decision
if p_value < alpha:
    print("Conclusion: Reject the null hypothesis. The new truck model has a different fuel mileage.")
else:
    print("Conclusion: Fail to reject the null hypothesis. No significant difference in fuel mileage.")














