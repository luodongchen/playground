from collections import Counter
import re

# 假设这是你的文件路径
file_path = '123.txt'  # 请替换为你的文件路径

# 读取文件内容
with open(file_path, 'r', encoding='utf-8') as f:
    text = f.read()  # 将整个文件内容读取到一个字符串中

# 使用正则表达式分割文本成单词，转化为小写
words = re.findall(r'\w+', text.lower())

# 计算每个词的频率
word_counts = Counter(words)

# 找出前二十个高频词
most_common_words = word_counts.most_common(60)  # 返回前20个高频词及其频率的列表

print("前二十个高频词是:")
for word, frequency in most_common_words:
    print(f"{word}: {frequency}")
