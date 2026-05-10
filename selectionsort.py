# Selection Sort in Python with User Input

arr = []

n = int(input("Enter number of elements: "))

# Taking input from user
for i in range(n):
    value = int(input("Enter element: "))
    arr.append(value)

# Selection Sort
for i in range(n):

    min_index = i

    for j in range(i + 1, n):

        if arr[j] < arr[min_index]:
            min_index = j

    # Swap elements
    arr[i], arr[min_index] = arr[min_index], arr[i]

print("\nSorted Array:")
print(arr)
