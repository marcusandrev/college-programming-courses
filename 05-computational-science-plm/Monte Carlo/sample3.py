import numpy as np

# Set up parameters
current_stock_price = 50
annual_mean_return = 0.1
annual_std_dev = 0.03
num_simulations = 10000
num_years = 1

# Generate simulated returns
simulated_returns = np.random.normal(loc=annual_mean_return, scale=annual_std_dev, size=num_simulations)

# Calculate future stock prices
future_stock_prices = current_stock_price * (1 + simulated_returns) ** num_years

# Analyze results
print("Estimated stock price after 1 year:", np.mean(future_stock_prices))

print("Median future stock price:", np.median(future_stock_prices))
print("Standard deviation of future stock prices:", np.std(future_stock_prices))
