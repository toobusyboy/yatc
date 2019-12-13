// 《自己动手写编译器、链接器》配套源代码

#include "scc.h"
#include <string.h>
#include <stdlib.h>

FILE *fin = NULL;
char *filename;
char *outfile;

/***********************************************************
 * 功能:	分配堆内存并将数据初始化为'0'
 * size: 分配内存大小
 **********************************************************/
void *mallocz(int size)
{
  void *ptr;
  ptr = malloc(size);
  if (!ptr && size)
    error("内存分配失败");
  memset(ptr, 0, size);
  return ptr;
}

/***********************************************************
 * 功能:	计算哈希地址
 * key:哈希关键字(为了与本书中SC语言关键字区分开，此处我们称为哈希关键字)
 * MAXKEY:哈希表长度
 **********************************************************/
int elf_hash(char *key)
{
  int h = 0, g;
  while (*key)
  {
    h = (h << 4) + *key++;
    g = h & 0xf0000000;
    if (g)
      h ^= g >> 24;
    h &= ~g;
  }
  return h % MAXKEY;
}

/***********************************************************
 * 功能:	初始化
 **********************************************************/
void init ()
{
  line_num = 1;
  init_lex();
}


/***********************************************************
 * 功能:	扫尾清理工作
 **********************************************************/
void cleanup()
{
  int i;
  for(i = TK_IDENT; i < tktable.count; i++)
  {
    free(tktable.data[i]);
  }
  free(tktable.data);
}

/***********************************************************
 * 功能:	得到文件扩展名
 * fname:	文件名称
 **********************************************************/
char *get_file_ext(char *fname)
{
  char *p;
  p = strrchr(fname,'.');
  return p+1;
}

/***********************************************************
 * 功能:	main主函数
 **********************************************************/
int main(int argc, char ** argv)
{
  (void)argc;

  fin = fopen(argv[1],"rb");
  if(!fin)
  {
    printf("不能打开SC源文件!\n");
    return 0;
  }
  init();
  getch();
  test_lex();
  cleanup();
  fclose(fin);
  printf("%s 词法分析成功!",argv[1]);
  return 1;
}
