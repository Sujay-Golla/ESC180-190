def drink_coffee():
    global current_time, last_coffee_time, last_coffee_time2, too_much_coffee
    if current_time - last_coffee_time2 <= 120 and last_coffee_time2 != 0 and current_time != 0:
        too_much_coffee = True
    last_coffee_time2 = last_coffee_time
    last_coffee_time = current_time


def study(minutes):
    global current_time, knols, last_coffee_time, last_coffee_time2, too_much_coffee
    current_time += minutes
    if too_much_coffee:
        knols += 0*minutes
    elif current_time - minutes == last_coffee_time:
        knols += 10*minutes
    else:
        knols += 5*minutes
    print(knols)

def initialize():
    global too_much_coffee
    global current_time
    global last_coffee_time
    global last_coffee_time2
    global knols
    too_much_coffee = False
    current_time = 0
    knols = 0
    last_coffee_time = -1e10000000000000000000000000000000
    last_coffee_time2 = -1e10000000000000000000000000000000

if __name__ == "__main__":
    initialize() # start the simulation
    study(60) # knols = 300
    study(20) # knols = 400
    drink_coffee() # knols = 400
    study(10) # knols = 500
    drink_coffee() # knols = 500
    study(10) # knols = 600
    drink_coffee() # knols = 600, 3rd coffee in 20 minutes
    study(10) # knols = 600