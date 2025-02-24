import numpy as np
import pandas as pd
from sklearn.model_selection import train_test_split
from sklearn.metrics import precision_score
from sklearn.ensemble import RandomForestClassifier

# 1. START
print("Starting Precision Estimation with Stratification...")

# 2. Prepare the dataset
np.random.seed(42)
data_size = 1000

# Generating synthetic dataset
df = pd.DataFrame({
    'feature1': np.random.randint(1, 100, data_size),
    'feature2': np.random.randint(1, 100, data_size),
    'stratum': np.random.choice(['A', 'B'], size=data_size, p=[0.5, 0.5]),  # Stratification variable
    'label': np.random.choice([0, 1], size=data_size)  # Binary classification
})

# Features and Target
X = df[['feature1', 'feature2']]
y = df['label']

# 3. Build a baseline model (without stratification)
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, random_state=42)
model_baseline = RandomForestClassifier()
model_baseline.fit(X_train, y_train)

# Predict and calculate precision
y_pred_baseline = model_baseline.predict(X_test)
baseline_precision = precision_score(y_test, y_pred_baseline)

# 4. Stratify the dataset based on 'stratum'
precision_list = []

for stratum in df['stratum'].unique():
    df_stratum = df[df['stratum'] == stratum]
    X_stratum = df_stratum[['feature1', 'feature2']]
    y_stratum = df_stratum['label']

    X_train_s, X_test_s, y_train_s, y_test_s = train_test_split(X_stratum, y_stratum, test_size=0.2, random_state=42)

    model_stratum = RandomForestClassifier()
    model_stratum.fit(X_train_s, y_train_s)
    
    y_pred_stratum = model_stratum.predict(X_test_s)
    precision_list.append(precision_score(y_test_s, y_pred_stratum))

# 6. Calculate Stratified Precision
stratified_precision = np.mean(precision_list)

# 7. Estimate Gain in Precision
gain_in_precision = stratified_precision - baseline_precision

# 8. Output Results
print(f"Baseline Precision: {baseline_precision:.4f}")
print(f"Stratified Precision: {stratified_precision:.4f}")
print(f"Gain in Precision Due to Stratification: {gain_in_precision:.4f}")

# 9. STOP


















