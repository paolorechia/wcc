import python_extension

def call_ext():
    return python_extension.count_bytes("test.txt")

bytes_ext = call_ext()
print(bytes_ext)