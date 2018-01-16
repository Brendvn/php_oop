<?php
/**
 * Created by PhpStorm.
 * User: Brend
 * Date: 2017/05/21
 * Time: 08:06 AM
 */
function __autoload($class_name){
    include $class_name.'.inc';
}


$output = new Behaviour();
echo $output;


