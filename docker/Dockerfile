# 使用官方镜像作为基础
FROM ubuntu:24.04

# 更新并安装 SSH 服务
RUN apt-get update && \
    apt-get install -y openssh-server \
    libelf1 \
    gcc \
    make \
    vim \
    git \
    && rm -rf /var/lib/apt/lists/*

# 创建 SSH 所需的目录
RUN mkdir -p /root/.ssh

# 复制本地的公钥到容器
COPY authorized_keys /root/.ssh/authorized_keys

# 设置正确的权限
RUN chmod 700 /root/.ssh && chmod 600 /root/.ssh/authorized_keys

# 修改 SSH 配置以允许使用密钥认证
RUN echo "PubkeyAuthentication yes" >> /etc/ssh/sshd_config
RUN echo "PasswordAuthentication no" >> /etc/ssh/sshd_config
RUN echo "PermitRootLogin yes" >> /etc/ssh/sshd_config

# sshd 运行所需
RUN mkdir /var/run/sshd

# 设置 SSH 服务默认启动
CMD ["/usr/sbin/sshd", "-D"]
