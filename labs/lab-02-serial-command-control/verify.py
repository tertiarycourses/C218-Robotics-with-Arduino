#!/usr/bin/env python3
from pathlib import Path
import sys
p=Path(__file__).parent/'solution'/'serial_command_control.ino'
text=p.read_text(encoding='utf-8')
required=['setup', 'loop', 'pinMode', 'Serial', 'digitalWrite']
missing=[x for x in required if x not in text]
if text.count('{') != text.count('}'): missing.append('balanced braces')
if missing:
    print('FAIL:', ', '.join(missing)); sys.exit(1)
print('PASS: serial_command_control.ino contains the expected Lab 2 mechanisms')
