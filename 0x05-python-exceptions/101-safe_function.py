#!/usr/bin/python3

def magic_calculation(a, b):
    result = 0

    for i in range(1, 4):  # Extend the loop range to cover more scenarios
        try:
            if i > a:
                raise ValueError(f"Value of i ({i}) is too large compared to a ({a})")

            result += a ** b / i
        except ValueError as ve:
            print(f"Error: {ve}")
            result = b + a
            break
        except Exception as e:
            print(f"An unexpected error occurred: {e}")
            result = b + a
            break

    return result

