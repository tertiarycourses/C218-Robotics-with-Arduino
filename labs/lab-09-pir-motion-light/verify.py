#!/usr/bin/env python3
from pathlib import Path
import sys
p=Path(__file__).parent/'solution'/'pir_motion_light.ino'
text=p.read_text(encoding='utf-8')
required=['setup', 'loop', 'pinMode', 'digitalRead', 'digitalWrite', 'millis']
missing=[x for x in required if x not in text]
if text.count('{') != text.count('}'): missing.append('balanced braces')
if missing:
    print('FAIL:', ', '.join(missing)); sys.exit(1)
print('PASS: pir_motion_light.ino contains the expected Lab 9 mechanisms')
