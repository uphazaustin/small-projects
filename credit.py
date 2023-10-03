# TODO
# Going to pass the number into this list so easier to apply Luhn's algorithm
digits = []
# Function to store the number into the list
def store_digits(num):
    if num == 0:
        return
    else:
        last_digit = int(num % 10)
        digits.append(last_digit)
        store_digits(int(num / 10) )

# Prompt the user for a number
# If wrong input, infinite prompt until user provides proper input
while True:
    try:
        print("Number:")
        number = int(input())
        store_digits(number)
        break
    except:
        print("Invalid number")

length = len(digits) # length of the number
sum = 0 # To keep track of the sum of the digits not multiplied by 2
sum_2 = 0 # To keep track of the sum of the digits multiplied by 2

if int(len(digits) % 2) == 0:

    for i in range(0, length, 2):
        num_2 = digits[i + 1]
        if 2*num_2 >= 10:
            num_2 = int(2*num_2)
            num_new_2 = int(num_2 % 10) + int(num_2 / 10)
            sum_2 += num_new_2
        else:
            sum_2 += 2*num_2
        num = digits[i]
        sum += num


if int(len(digits) % 2 ) > 0: ## **fix**

    for i in range(0, length, 2):
        num = digits[i]
        if i == 0:
            sum += num
        else:
            num_2 = digits[i - 1]
            if 2*num_2 >= 10:
                num_2 = 2*num_2
                num_2 = int(num_2 % 10) + int(num_2 / 10)
                sum_2 += num_2
            else:
                sum_2 += 2*num_2
            sum += num

if ((sum + sum_2) % 10) == 0:
    sec_digits = [1, 2, 3, 4, 5]
    if digits[length - 1] == 4 and (len(digits) == 13 or len(digits) == 16):
        print("VISA")
    else:
        print("INVALID")
    if digits[length - 1] == 5:
        for i in range(5):
            if digits[length - 2] == sec_digits[i]:
                print("MASTERCARD")
            else:
                print("INVALID")

    if digits[length - 1] == 3:
        if digits[length - 2] == 4 or digits[length - 2] == 7:
            print("AMEX")
        else:
            print("INVALID")
else:
    print("INVALID")

print()
