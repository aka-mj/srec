# SREC library and utilities

This repository contains a library and utilities for manipulating Motorola S-record files.

## Library

The library can be found under the 'srec' directory.

## Utilities

### bin2srec

This utility converts a binary file to an S-record file.

Usage:
```
bin2srec -i <input file> -o <output file> -b <address_bits> --checksum
```

Example:
```
bin2srec -i input.bin -o output.srec -b 16 --checksum
```

### srec2bin

This utility converts an S-record file to a binary file.

Usage:
```
srec2bin -i <input file> -o <output file>
```

Example:
```
srec2bin -i input.srec -o output.bin
```

### sreccheck

This utility checks the CRC32 of an S-record file.
The checksum is expected to be the first S0 line of the file.

Usage:
```
sreccheck <input file> [--verbose]
```

Example:
```
sreccheck input.srec --verbose
sreccheck input.srec
```

