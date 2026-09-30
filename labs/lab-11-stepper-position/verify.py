#!/usr/bin/env python3
from pathlib import Path
import sys
p=Path(__file__).parent/'solution'/'stepper_position.ino'
text=p.read_text(encoding='utf-8')
required=['setup', 'loop', 'Stepper']
missing=[x for x in required if x not in text]
if text.count('{') != text.count('}'): missing.append('balanced braces')
if missing:
    print('FAIL:', ', '.join(missing)); sys.exit(1)
print('PASS: stepper_position.ino contains the expected Lab 11 mechanisms')
