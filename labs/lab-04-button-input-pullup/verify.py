#!/usr/bin/env python3
from pathlib import Path
import sys
p=Path(__file__).parent/'solution'/'button_input_pullup.ino'
text=p.read_text(encoding='utf-8')
required=['setup', 'loop', 'pinMode', 'digitalRead', 'digitalWrite', 'INPUT_PULLUP', 'millis']
missing=[x for x in required if x not in text]
if text.count('{') != text.count('}'): missing.append('balanced braces')
if missing:
    print('FAIL:', ', '.join(missing)); sys.exit(1)
print('PASS: button_input_pullup.ino contains the expected Lab 4 mechanisms')
