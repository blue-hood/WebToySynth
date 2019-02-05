FROM centos

MAINTAINER bluehood_admin

RUN yum install -y httpd

CMD ["/usr/sbin/httpd", "-D", "FOREGROUND"]

