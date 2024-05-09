import re
from collections import Counter

file_path = '123.txt'  # 请替换为你的文件路径

# 读取文件内容
with open(file_path, 'r', encoding='utf-8') as f:
    text = f.read()  # 将整个文件内容读取到一个字符串中

# 分割文本为句子
# 使用正则表达式匹配句子的结束符号
sentences = re.split(r'(?<=[.!?]) +', text.strip())  # 这个正则表达式可以分割句子

# 使用Counter计算句子的频率
sentence_counts = Counter(sentences)

# 找出最高频的句子
most_common_sentence = sentence_counts.most_common(1)  # 返回最高频的句子及其频率

print("最高频的句子是:", most_common_sentence[0][0])
print("频率是:", most_common_sentence[0][1])

# 如果你想找到前N个高频句子
N = 40
most_common_sentences = sentence_counts.most_common(N)

print("前{}个高频句子是:".format(N))
for sentence, frequency in most_common_sentences:
    print(f'"{sentence}" - {frequency}次')
