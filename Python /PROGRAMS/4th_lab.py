numbers = tuple(map(int, input("Enter numbers separated by space: ").split()))

even_tuple = tuple(num for num in numbers if num % 2 == 0)
odd_tuple = tuple(num for num in numbers if num % 2 != 0)

print("Even Tuple:", even_tuple)
print("Odd Tuple:", odd_tuple)





# Step 1: Create a dictionary
book_stock = {
    "Python Basics": 10,
    "Data Science Handbook": 5,
    "Machine Learning Guide": 8
}

# Step 2: Access values
print("Stock of 'Python Basics':", book_stock["Python Basics"])

# Step 3: Add or update values
book_stock["Deep Learning Essentials"] = 7  # Adding a new book
book_stock["Python Basics"] = 12  # Updating stock

# Step 4: Remove key-value pair
del book_stock["Data Science Handbook"]

# Step 5: Check if a key exists
book = "Machine Learning Guide"
if book in book_stock:
    print(f"{book} is available in stock.")

# Step 6: Get all keys
print("Available books:", list(book_stock.keys()))

# Step 7: Find length of dictionary
print("Total number of books:", len(book_stock))

# Step 8: Merge dictionary
new_books = {"AI for Beginners": 4, "Cloud Computing": 6}
book_stock.update(new_books)

# Step 9: Print updated dictionary
print("Updated Book Stock:", book_stock)












with open("numbers.txt", "r") as file:
    numbers = map(int, file.read().split())

primes = []
for num in numbers:
    if num > 1:
        is_prime = True
        for i in range(2, int(num ** 0.5) + 1):
            if num % i == 0:
                is_prime = False
                break
        if is_prime:
            primes.append(num)

print("Prime Numbers:", primes)









import string

with open("textfile.txt", "r") as file:
    text = file.read()

word_count = len(text.split())
sentence_count = text.count('.') + text.count('!') + text.count('?')
uppercase_count = sum(1 for char in text if char.isupper())
lowercase_count = sum(1 for char in text if char.islower())
special_symbol_count = sum(1 for char in text if char in string.punctuation)

print("Word Count:", word_count)
print("Sentence Count:", sentence_count)
print("Uppercase Letters:", uppercase_count)
print("Lowercase Letters:", lowercase_count)
print("Special Symbols:", special_symbol_count)
