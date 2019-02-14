FROM centos

MAINTAINER bluehood_admin

RUN yum install -y httpd
RUN ln -sf /dev/stdout /var/log/httpd/access_log
RUN ln -sf /dev/stderr /var/log/httpd/error_log

CMD ["/usr/sbin/httpd", "-D", "FOREGROUND"]

