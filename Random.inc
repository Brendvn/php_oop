<?php

/**
 * Created by PhpStorm.
 * User: Brend
 * Date: 2017/05/21
 * Time: 09:37 AM
 */
class Random implements Model
{
    private $status='';
    private $obj = array();
    private $visitobj = array();
    private $color='';
    private $create=false;

    /**
     * Random constructor.
     * @param array $data
     */
    public function random($data=array()){
        if(count($data)>0){
            $ran = $data;
            $randomElement = $ran[array_rand($ran, 1)];
            return $randomElement;
        }

    }


    /**
     * This method looks for flower that is currently open then creates array for use
     * @param int $value
     * @return int|string
     */
    public function randomvisits($value=0){

       $birdobj = Birds::$birdobj;
       $this->obj = array();

       foreach(Flowers::$obj as $row){
           $this->status =  $row['flower']['status'];

           if ($this->status =='Open'){
               $arr = array('flower' =>array(
                   'name' => $row['flower']['name'],
                   'color'=>$row['flower']['color'],
               ));
               array_push($this->obj, $arr);
           }

       }
        $this->createarray($this->obj);
        if(count($this->obj)>0){

            $flowerobj = $this->random($this->obj);
            $birdobj = $this->random($birdobj);

            $value = $this->visitcalculation($flowerobj['flower']['name'],$flowerobj['flower']['color'],$birdobj['birds']['name']);

            return $value;

        }

    }

    /**
     * This method sets array with attributes to see which bird accessed which flower
     * and looks for if bird visits same color in a row to create new flower
     * @param string $flower
     * @param string $color
     * @param string $bird
     * @return string
     */
    private function visitcalculation($flower='', $color='', $bird=''){

        $value='';
        if($this->color==$color){
            $this->create= true;
        }

        for($i=0;$i<count($this->visitobj);$i++){
            if($this->visitobj[$i]['flower']['name']==$flower){
                if(strpos($this->visitobj[$i]['flower']['birds'],$bird) ==false){
                    $names =$this->visitobj[$i]['flower']['birds'];
                    $this->visitobj[$i]['flower']['birds'] .= ' '.$bird;
                }

            }
        }
        if ($this->create){
            $value =  $this->color;

        }

        $this->create = false;
        if($this->color==''){
            $this->color = $color;
        }else{
            $this->color = $color;
        }

        return $value;
    }

    private function createarray($data=array()){

        if(!count($this->visitobj)>0) {
            foreach ($data as $row) {
                $arr = array('flower' => array(
                    'name' => $row['flower']['name'],
                    'color' => $row['flower']['color'],
                    'birds' => '',
                ));
                array_push($this->visitobj, $arr);
            }
        }

    }





}