#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
struct e_header_x64{
  uint32_t magic;
  uint8_t arch;
  uint8_t endian;
  uint8_t version;
  uint8_t abi_int;
  uint8_t abi_ver;
  unsigned long padding:            56;
  uint16_t obj_type;
  uint16_t i_s_arch;
  uint32_t e_version;
  unsigned long entry:              64;
  unsigned long e_phoff:            64; // start of program header
  unsigned long e_shoff:            64; // start of section header
  uint32_t e_flags;
  uint16_t e_ehsize;
  // size of a program header table entry
  uint16_t e_phentsize;
  uint16_t e_phnum; // num entries in program header table
  uint16_t e_shentsize; // size of section header table entry
  uint16_t e_shnum; // number of entries in section header table
  uint16_t e_shstrndx; // index of section header table  


    
};

int main(){
  FILE * fp = fopen("ret","rb");
  // struct ef;
  fseek(fp,0L,SEEK_END);
  int sz = ftell(fp);
  rewind(fp);
  unsigned char * buffer = (unsigned char *)malloc(sz);
  fread(buffer,sizeof(buffer),sz,fp);
  struct e_header_x64 * ef = (struct e_header_x64 *)buffer;
  printf("0x%02x\n",ef->abi_int);
  free(buffer);
  fclose(fp);
}