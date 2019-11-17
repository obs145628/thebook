import os
import sys

CMD_EMIT_S  = "{} -O{} -S {} -o {}_o{}.s"
CMD_EMIT_LL = "{} -O{} -S -emit-llvm {} -o {}_o{}.ll"
ROOT_DIR = sys.argv[1]
CC_COMPILER = os.getenv('CC')
CXX_COMPILER = os.getenv('CXX')

fails = []

def list_src(path):
    c_files = []
    cxx_files = []

    for ppath, pdirs, pfiles in os.walk(path):

        c_files += [os.path.join(ppath, x) for x in pfiles if x.endswith('.c')]
        cxx_files += [os.path.join(ppath, x) for x in pfiles
                      if x.endswith('.cc') or x.endswith('.cpp')]

    return c_files, cxx_files


def gen_code(src, levels=[0, 1, 2, 3]):
    print('Compiling {}...'.format(src))
    src_name, src_ext = os.path.splitext(src)
    cc = CC_COMPILER if src_ext == '.c' else CXX_COMPILER
    if cc is None:
        print('Cannot compile {}: env variable CC or CXX not defined'.format(src))
        sys.exit(1)

    for ol in levels:
        cmd_ll = CMD_EMIT_LL.format(cc, ol, src, src_name, ol)
        cmd_s = CMD_EMIT_S.format(cc, ol, src, src_name, ol)
        if os.system(cmd_ll) != 0:
            fails.append('Compile to LLVM IR: command failed: {}'.format(cmd_ll))
        if os.system(cmd_s) != 0:
            fails.append('Compile to ASM: command failed: {}'.format(cmd_s))



c_files, cxx_files = list_src(ROOT_DIR)


[gen_code(f) for f in c_files]
[gen_code(f) for f in cxx_files]

print('Done. Compiled {} C files and {} C++ files'.format(len(c_files), len(cxx_files)))
print('Got {} errors:'.format(len(fails)))
for err in fails: print(err)
