m = 0x1025544
mask = 0xffff
print("LOB = " + str(hex(m & mask)))			# retrieve 5544
print("HOB = " + str(hex(mask & (m >> 16))))	# retrieve 0102
