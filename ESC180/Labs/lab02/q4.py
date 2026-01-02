def display_current_value():
    print(val)
def add(to_add):
    global val, prev_value, value_before
    value_before = prev_value
    prev_value = val
    val += to_add
def mult(to_mult):
    global val, prev_value, value_before
    value_before = prev_value
    prev_value = val
    val *= to_mult
def div(to_div):
    global val, prev_value, value_before
    if to_div != 0:
        value_before = prev_value
        prev_value = val
        val /= to_div
    else:
        print("Not possible")
def memory():
    global saved
    saved = val
def recall():
    global val
    val = saved
def undo():
    global val, prev_value
    prev_value, val = val, prev_value
    display_current_value()
def undo2():
    global val, prev_value, value_before
    value_before, prev_value, val = prev_value, val, value_before
    display_current_value()
if __name__ == "__main__":
    print("Welcome to the calculator program.")
    val = 0
    saved = 0
    prev_value = 0
    value_before = 0
    print("Current value:", val)
    display_current_value() # should display 0
    add(5)
    display_current_value() # should display 5
    add(10)
    display_current_value() # should display 15
    mult(5)
    display_current_value() # should display 75
    mult(10)
    display_current_value() # should display 750

    memory()

    # For the div function, 0 and strings would cause problems
    div(-5)
    display_current_value() # should display -150
    div(10.5)
    display_current_value() # should display -14.3 ish

    recall()
    display_current_value()

    add(5) # current value: 755
    mult(2) # current value: 1510
    undo() # current value: 755
    undo() # current value: 1510
    undo() # current value: 755

    undo2()







