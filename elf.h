// Format of an ELF executable file

#define ELF_MAGIC 0x464C457FU  // "\x7FELF" in little endian

// File header
struct elfhdr {
  uint magic;  // must equal ELF_MAGIC
  uchar elf[12];
  ushort type;
  ushort machine;
  uint version;
  uint entry;  // entry point 
  uint phoff;  // start of program headers
  uint shoff;  // start of section headers
  uint flags;
  ushort ehsize;     // size of this header
  ushort phentsize;  // size of a program header
  ushort phnum;      // number of program headers
  ushort shentsize;  // size of a section header 
  ushort shnum;      // number of section headers
  ushort shstrndx;   // section header string table index
};

// Program header
struct proghdr {
  uint type;
  uint off;
  uint vaddr;
  uint paddr;
  uint filesz;
  uint memsz;
  uint flags;
  uint align;
};

// Values for Proghdr type
#define ELF_PROG_LOAD           1

// Flag bits for Proghdr flags
#define ELF_PROG_FLAG_EXEC      1
#define ELF_PROG_FLAG_WRITE     2
#define ELF_PROG_FLAG_READ      4
