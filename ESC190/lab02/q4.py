def binary_search_deluxe(arr, target):
    return [binary_search_left(arr, target), binary_search_right(arr, target)]

def binary_search_left(arr, target):
    low = 0
    high = len(arr) - 1
        
    while low <= high:
        mid = (low + high) // 2
        if arr[mid] < target:
            low = mid + 1
        else:
            high = mid - 1
    
    return low

def binary_search_right(arr, target):
    low = 0
    high = len(arr) - 1

    while low <= high:
        mid = (low + high) // 2
        if target < arr[mid]:
            high = mid - 1
        else:
            low = mid + 1

    return high


if __name__ == "__main__":
    arr = [1, 2, 2, 2, 3, 4, 5]
    target = 2
    result = binary_search_deluxe(arr, target)
    print(f"First and last occurrence of {target} in {arr} is at indices: {result}")