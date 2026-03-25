def change_name(person, new_name):
    person[0] = new_name
    
student = ["Alice", 20]
change_name(student, "Bob")
print(student)

"""
Memory diagram before change_name is called:
student --> ["Alice", 20]
             ^
             |
          person

After calling change_name(student, "Bob"):
student --> ["Bob", 20]
             ^
             |
          person
"""