# LEVEL 8

This is a simple one.

We are asked to enter an input through stdin.

4 options:
- "auth " -> 4 bytes are malloced, if what's left after buf+5 is <=30, it is strcpyied at the malloc's addr (first exploit: we can copy more bytes than what was allocated)
- reset -> frees the allocated bytes
- service -> duplicates everyting after "service", logically right after the 4 allocated bytes of "auth" (or before if we typed service first, but no interest in this)
- login : checks if there is sthg at auth[0x20[, after the boundarie set (30 bytes), if so, opens a shell whith level9's rights

We just have to use the service command to fill a lot of bytes since there are no restrictions, and overwrite auth[0x20].
